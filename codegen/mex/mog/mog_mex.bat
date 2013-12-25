@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2013a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2013a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=mog_mex
set MEX_NAME=mog_mex
set MEX_EXT=.mexw64
call mexopts.bat
echo # Make settings for mog > mog_mex.mki
echo COMPILER=%COMPILER%>> mog_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> mog_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> mog_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> mog_mex.mki
echo LINKER=%LINKER%>> mog_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> mog_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> mog_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> mog_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> mog_mex.mki
echo BORLAND=%BORLAND%>> mog_mex.mki
echo OMPFLAGS= >> mog_mex.mki
echo OMPLINKFLAGS= >> mog_mex.mki
echo EMC_COMPILER=msvc110>> mog_mex.mki
echo EMC_CONFIG=optim>> mog_mex.mki
"C:\Program Files\MATLAB\R2013a\bin\win64\gmake" -B -f mog_mex.mk
