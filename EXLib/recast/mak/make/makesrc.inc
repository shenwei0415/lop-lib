################################################################
#����ļ��е���������Թ̶�����ģ���Ҫ�޸ģ���֪ͨAARONͳһ����
################################################################
ifndef fun_loop_dir
define fun_loop_dir
	@for i in $1 ; \
	do \
		echo "make["$(MAKELEVEL)"]: "$(MAKE) $(MAKE_TARGET) $(TARGET) "-C" $$i";"; \
		$(MAKE) $(MAKE_TARGET) -C $$i || exit "$$?" ;\
	done
endef
endif

MAKE_TARGET=$@

CURRENTDIR=$(shell pwd)

target: debug release

debug:
	$(call fun_loop_dir, $(MAKESRC), $(CURRENTDIR))
	
release:
	$(call fun_loop_dir, $(MAKESRC), $(CURRENTDIR))

.DEFAULT:
	$(call fun_loop_dir, $(MAKESRC), $(CURRENTDIR))