# invoke SourceDir generated makefile for app.pe66
app.pe66: .libraries,app.pe66
.libraries,app.pe66: package/cfg/app_pe66.xdl
	$(MAKE) -f D:\pxqwork\project\5G-DSP\5G_basic_platform_master/src/makefile.libs

clean::
	$(MAKE) -f D:\pxqwork\project\5G-DSP\5G_basic_platform_master/src/makefile.libs clean

