/* C glue code needed by PowerPC native version of DTSA to call compatible plug-ins.	CallUniversalProc can't be called directly from Pascal because is uses a variable	number of arguments.   uppCallCodeInfo = $00003F80; { PROCEDURE (2 byte param, 4 byte param, 4 byte param, 4 byte param);*/#if GENERATINGPOWERPC#include <Types.h>#define uppDTSAAcquirePlugInProcInfo						\	(kPascalStackBased | RESULT_SIZE(kNoByteCode) |			\	 STACK_ROUTINE_PARAMETER(1, kTwoByteCode)     |			\	 STACK_ROUTINE_PARAMETER(2, kFourByteCode)    |			\	 STACK_ROUTINE_PARAMETER(3, kFourByteCode)    |			\	 STACK_ROUTINE_PARAMETER(4, kFourByteCode))#define uppDTSAFilePlugInProcInfo							\	(kPascalStackBased | RESULT_SIZE(kNoByteCode) |			\	 STACK_ROUTINE_PARAMETER(1, kTwoByteCode)     |			\	 STACK_ROUTINE_PARAMETER(2, kFourByteCode)    |			\	 STACK_ROUTINE_PARAMETER(3, kFourByteCode))pascal void CallAcquirePlug(short selector, Ptr AcqRecPtr, long *data, short *result, UniversalProcPtr codePtr);pascal void CallFilePlug(short selector, Ptr *theFilePtr, short *result, UniversalProcPtr codePtr);//***************************************************************************************************************pascal void CallAcquirePlug(short selector, Ptr AcqRecPtr, long *data, short *result, UniversalProcPtr codePtr){	CallUniversalProc(codePtr, uppDTSAAcquirePlugInProcInfo, selector, AcqRecPtr, data, result);}pascal void CallFilePlug(short selector, Ptr *theFilePtr, short *result, UniversalProcPtr codePtr){	CallUniversalProc(codePtr, uppDTSAFilePlugInProcInfo, selector, theFilePtr, result);}#endif