

from pathlib import Path
import re
import sys

matchFunc = re.compile("META_.*FUNC.*\((?P<funcName>.*)\)")



def ReadLines(filename: str):
    for encode in ['gbk', 'utf-8']:
        try:
            with open(filename, 'r', encoding=encode) as fp:
                return fp.readlines()
        except:
            continue

class FuncInfo:
    def __init__(self):
        self.funcName = None

class ClassInfo:
    def __init__(self):
        self.className = None
        self.lFuncInfo = []

    def AddFuncInfo(self, info):
        self.lFuncInfo.append(info)

    def Save(self):
        lines = []
        s = "void %s::RegisterAllMethod() {" % self.className
        lines.append(s)
        prefix = '\t'
        for funcInfo in self.lFuncInfo:
            s = prefix + "REGISTER_FUNC(%s);" % funcInfo.funcName
            lines.append(s)
        lines.append('}')
        text = '\n'.join(lines)
        return text

class HeadFileInfo:
    def __init__(self):
        self.filePath = ''
        self.fileName = ''
        self.dClassInfo = {}
        self.curClass = None

    def Load(self, filePath):
        self.filePath = filePath
        self.fileName = Path(filePath).name
        lines = ReadLines(filePath)
        for line in lines:
            self.UpdateClassInfo(line)
            funcName = self.GetFuncName(line)
            if funcName:
                funcInfo = FuncInfo()
                funcInfo.funcName = funcName
                self.curClass.AddFuncInfo(funcInfo)

    def Save(self):
        assert self.fileName, '文件名为空'
        lines = []
        s = '#include "%s" ' % self.fileName
        lines.append(s)
        for classInfo in self.dClassInfo.values():
            s = classInfo.Save()
            lines.append(s)

        if len(lines) == 1:
            return ''
        text = '\n'.join(lines)
        return text


    def UpdateClassInfo(self, line: str):
        ret = re.search(".*META_OBJECT\((?P<className>\w+).*\)", line)
        if ret:
            className = ret.group("className")
            if self.curClass is None or self.curClass.className != className:
                self.curClass = ClassInfo()
                self.curClass.className = className
                self.dClassInfo[className] = self.curClass
                return True
        return False

    def GetFuncName(self, line: str):
        ret = re.search("META_.*FUNC.*\((?P<params>.*)\)", line)
        if ret:
            params = ret.group("params")
            funcName = params.split(",")[0].strip()
            return funcName


class RegisterFuncMgr:
    def __init__(self):
        self.lHeadFileInfo = []
        self.lFilters = ["MetaObject.h"]

    def Load(self, rootPath):
        self.lHeadFileInfo.clear()
        for headFilePath in Path(rootPath).rglob("*.h"):
            if self.CheckInFilters(headFilePath.name):
                print('filtered head file:', headFilePath)
                continue
            print('cur head file===>', headFilePath.as_posix())
            headInfo = HeadFileInfo()
            headInfo.Load(headFilePath)
            self.lHeadFileInfo.append(headInfo)

    def Save(self, filePath):
        filePath = Path(filePath)
        lines = []
        for headFileInfo in self.lHeadFileInfo:
            s = headFileInfo.Save()
            lines.append(s)

        text = '\n'.join(lines)

        if filePath.exists():
            data = ''.join(ReadLines(filePath))
            if text == data:
                print('不需要更新')
                return

        with open(filePath, 'w') as fp:
            fp.write(text)

    def CheckInFilters(self, fileName):
        for f in self.lFilters:
            if fileName == f:
                return True
        return False


def TestRegex():
    s = "META_FUNC(GetScaledVolumn, int, int, scale);"
    s = "META_VOID_FUNC_VOID(GetScaledVolumn);"
    r = re.search("META_.*FUNC.*\((?P<params>.*)\)", s)
    if r:
        param_text = r.group("params")
        funcName = param_text.split(",")[0].strip()

        print(funcName)





TestRegex()

testFilePath = r'F:\TestReflection\源.cpp'
testSavePath = 'registerFunc.cpp'
# sys.argv = '', testFilePath, testSavePath
if __name__ == '__main__':
    mgr = RegisterFuncMgr()
    print('====>', sys.argv)
    _, filePath, savePath = sys.argv
    mgr.Load(filePath)
    mgr.Save(savePath)


