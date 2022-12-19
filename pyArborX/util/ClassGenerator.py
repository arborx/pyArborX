from typing import List

class ClassGenerator():
    def __init__(self,pythonClassName: str,cppClassName: str,classTemplateArgs: List[str]):
        self.pythonClassName: str = pythonClassName
        self.cppClassName: str = cppClassName
        self.classTemplateArgs: str = classTemplateArgs
        self.ctor: List[str] = []

    def addCtor(self, argTypes: List[str], argNames: List[str]) -> None:

        source = ".def(py::init<"
        #ctor with args
        if argTypes:
            argTypeList: str = ",".join(argTypes)
            source += f"{argTypeList}>(),"
            pyArgNames = ",".join([f"py::arg({arg})" for arg in argNames])
            source += f"{pyArgNames}"
            source += ")"
        #default ctor
        else:
            source += ">())"

        self.ctor.append(source)

    def getBindingSource(self) -> List[str]:
        source: List[str] = []
        source.append(f"py::class_<{self.cppClassName}<{self.classTemplateArgs}>>(m,{self.pythonClassName})")
        source.append("".join(self.ctor))
