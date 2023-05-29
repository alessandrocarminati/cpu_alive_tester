################################################################################
#
# cpu_tester
#
################################################################################

CPU_TESTER_VERSION = 0.06
CPU_TESTER_SOURCE = v$(CPU_TESTER_VERSION).tar.gz
CPU_TESTER_SITE = https://github.com/alessandrocarminati/cpu_alive_tester/archive/refs/tags
CPU_TESTER_CFLAGS += -static

define CPU_TESTER_CONFIGURE_CMDS
	$(QUIET) : # Empty command
endef

define CPU_TESTER_BUILD_CMDS
	$(TARGET_MAKE_ENV) $(MAKE) -C $(@D) $(TARGET_CONFIGURE_OPTS)
endef

define CPU_TESTER_INSTALL_TARGET_CMDS
	$(TARGET_MAKE_ENV) $(MAKE) -C $(@D) DESTDIR=$(TARGET_DIR) PREFIX=$(TARGET_DIR) TOOLCHAIN_PREFIX=$(TARGET_CROSS) install
endef
$(eval $(generic-package))
