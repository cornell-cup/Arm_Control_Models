function CodeDefine() { 
this.def = new Array();
this.def["IsrOverrun"] = {file: "ert_main_c.html",line:4,type:"var"};
this.def["OverrunFlag"] = {file: "ert_main_c.html",line:5,type:"var"};
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:6,type:"fcn"};
this.def["stopRequested"] = {file: "ert_main_c.html",line:33,type:"var"};
this.def["main"] = {file: "ert_main_c.html",line:34,type:"fcn"};
this.def["Arduino_Blinking_LED_DW"] = {file: "Arduino_Blinking_LED_c.html",line:27,type:"var"};
this.def["Arduino_Blinking_LED_M_"] = {file: "Arduino_Blinking_LED_c.html",line:30,type:"var"};
this.def["Arduino_Blinking_LED_M"] = {file: "Arduino_Blinking_LED_c.html",line:31,type:"var"};
this.def["SystemProp_matlabCodegenSetAnyP"] = {file: "Arduino_Blinking_LED_c.html",line:38,type:"fcn"};
this.def["matlabCodegenHandle_matlabCodeg"] = {file: "Arduino_Blinking_LED_c.html",line:44,type:"fcn"};
this.def["Arduino_Blinking_LED_step"] = {file: "Arduino_Blinking_LED_c.html",line:52,type:"fcn"};
this.def["Arduino_Blinking_LED_initialize"] = {file: "Arduino_Blinking_LED_c.html",line:124,type:"fcn"};
this.def["Arduino_Blinking_LED_terminate"] = {file: "Arduino_Blinking_LED_c.html",line:177,type:"fcn"};
this.def["DW_Arduino_Blinking_LED_T"] = {file: "Arduino_Blinking_LED_h.html",line:63,type:"type"};
this.def["codertarget_arduinobase_block_T"] = {file: "Arduino_Blinking_LED_types_h.html",line:32,type:"type"};
this.def["P_Arduino_Blinking_LED_T"] = {file: "Arduino_Blinking_LED_types_h.html",line:37,type:"type"};
this.def["RT_MODEL_Arduino_Blinking_LED_T"] = {file: "Arduino_Blinking_LED_types_h.html",line:40,type:"type"};
this.def["Arduino_Blinking_LED_P"] = {file: "Arduino_Blinking_LED_data_c.html",line:25,type:"var"};
this.def["long_T"] = {file: "multiword_types_h.html",line:28,type:"type"};
this.def["int64m_T"] = {file: "multiword_types_h.html",line:35,type:"type"};
this.def["cint64m_T"] = {file: "multiword_types_h.html",line:40,type:"type"};
this.def["uint64m_T"] = {file: "multiword_types_h.html",line:44,type:"type"};
this.def["cuint64m_T"] = {file: "multiword_types_h.html",line:49,type:"type"};
this.def["int96m_T"] = {file: "multiword_types_h.html",line:53,type:"type"};
this.def["cint96m_T"] = {file: "multiword_types_h.html",line:58,type:"type"};
this.def["uint96m_T"] = {file: "multiword_types_h.html",line:62,type:"type"};
this.def["cuint96m_T"] = {file: "multiword_types_h.html",line:67,type:"type"};
this.def["int128m_T"] = {file: "multiword_types_h.html",line:71,type:"type"};
this.def["cint128m_T"] = {file: "multiword_types_h.html",line:76,type:"type"};
this.def["uint128m_T"] = {file: "multiword_types_h.html",line:80,type:"type"};
this.def["cuint128m_T"] = {file: "multiword_types_h.html",line:85,type:"type"};
this.def["int160m_T"] = {file: "multiword_types_h.html",line:89,type:"type"};
this.def["cint160m_T"] = {file: "multiword_types_h.html",line:94,type:"type"};
this.def["uint160m_T"] = {file: "multiword_types_h.html",line:98,type:"type"};
this.def["cuint160m_T"] = {file: "multiword_types_h.html",line:103,type:"type"};
this.def["int192m_T"] = {file: "multiword_types_h.html",line:107,type:"type"};
this.def["cint192m_T"] = {file: "multiword_types_h.html",line:112,type:"type"};
this.def["uint192m_T"] = {file: "multiword_types_h.html",line:116,type:"type"};
this.def["cuint192m_T"] = {file: "multiword_types_h.html",line:121,type:"type"};
this.def["int224m_T"] = {file: "multiword_types_h.html",line:125,type:"type"};
this.def["cint224m_T"] = {file: "multiword_types_h.html",line:130,type:"type"};
this.def["uint224m_T"] = {file: "multiword_types_h.html",line:134,type:"type"};
this.def["cuint224m_T"] = {file: "multiword_types_h.html",line:139,type:"type"};
this.def["int256m_T"] = {file: "multiword_types_h.html",line:143,type:"type"};
this.def["cint256m_T"] = {file: "multiword_types_h.html",line:148,type:"type"};
this.def["uint256m_T"] = {file: "multiword_types_h.html",line:152,type:"type"};
this.def["cuint256m_T"] = {file: "multiword_types_h.html",line:157,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:28,type:"type"};
this.def["ret"] = {file: "MW_digitalio_cpp.html",line:31,type:"var"};
this.def["getLoopbackIP"] = {file: "MW_target_hardware_resources_h.html",line:11,type:"var"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["Arduino_Blinking_LED_c.html"] = "../Arduino_Blinking_LED.c";
	this.html2Root["Arduino_Blinking_LED_c.html"] = "Arduino_Blinking_LED_c.html";
	this.html2SrcPath["Arduino_Blinking_LED_h.html"] = "../Arduino_Blinking_LED.h";
	this.html2Root["Arduino_Blinking_LED_h.html"] = "Arduino_Blinking_LED_h.html";
	this.html2SrcPath["Arduino_Blinking_LED_private_h.html"] = "../Arduino_Blinking_LED_private.h";
	this.html2Root["Arduino_Blinking_LED_private_h.html"] = "Arduino_Blinking_LED_private_h.html";
	this.html2SrcPath["Arduino_Blinking_LED_types_h.html"] = "../Arduino_Blinking_LED_types.h";
	this.html2Root["Arduino_Blinking_LED_types_h.html"] = "Arduino_Blinking_LED_types_h.html";
	this.html2SrcPath["Arduino_Blinking_LED_data_c.html"] = "../Arduino_Blinking_LED_data.c";
	this.html2Root["Arduino_Blinking_LED_data_c.html"] = "Arduino_Blinking_LED_data_c.html";
	this.html2SrcPath["multiword_types_h.html"] = "../multiword_types.h";
	this.html2Root["multiword_types_h.html"] = "multiword_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["rtmodel_h.html"] = "../rtmodel.h";
	this.html2Root["rtmodel_h.html"] = "rtmodel_h.html";
	this.html2SrcPath["MW_digitalio_cpp.html"] = "../../../../../../../../../ProgramData/MATLAB/SupportPackages/R2018a/toolbox/target/supportpackages/arduinobase/src/MW_digitalio.cpp";
	this.html2Root["MW_digitalio_cpp.html"] = "MW_digitalio_cpp.html";
	this.html2SrcPath["MW_target_hardware_resources_h.html"] = "../MW_target_hardware_resources.h";
	this.html2Root["MW_target_hardware_resources_h.html"] = "MW_target_hardware_resources_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","Arduino_Blinking_LED_c.html","Arduino_Blinking_LED_h.html","Arduino_Blinking_LED_private_h.html","Arduino_Blinking_LED_types_h.html","Arduino_Blinking_LED_data_c.html","multiword_types_h.html","rtwtypes_h.html","rtmodel_h.html","MW_digitalio_cpp.html","MW_target_hardware_resources_h.html"];
