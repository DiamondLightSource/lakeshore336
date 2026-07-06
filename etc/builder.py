from iocbuilder import AutoSubstitution, Device
from iocbuilder.modules.streamDevice import AutoProtocol

class lakeshore336(AutoSubstitution, AutoProtocol, Device):
    """ Support for lakeshore 336 controller"""
    
    DbdFileList=['lakeshore336Support']
    LibFileList=['lakeshore336']
    # Substitution
    TemplateFile = "lakeshore336.template"
    # AutoProtocol attributes
    ProtocolFiles = ['lakeshore336.proto']

    
