# Makefile for hello_kernel.ko
#
# This Makefile builds a Linux Kernel Module (LKM) against the current
# running kernel headers. It uses the kernel build system to ensure
# compatibility and proper compilation.

# The name of the module (without .ko extension)
obj-m += hello_kernel.o

# Kernel source directory - uses the current running kernel
KERNEL_DIR ?= /lib/modules/$(shell uname -r)/build

# Default target
all: modules

# Build the module
modules:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

# Clean build artifacts
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean

# Install the module (requires root privileges)
install:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules_install

# Uninstall the module
uninstall:
	rm -f /lib/modules/$(shell uname -r)/extra/hello_kernel.ko
	depmod -a

# Help target
help:
	@echo "Available targets:"
	@echo "  all       - Build the kernel module (default)"
	@echo "  modules   - Build the kernel module"
	@echo "  clean     - Clean build artifacts"
	@echo "  install   - Install the module (requires root)"
	@echo "  uninstall - Uninstall the module (requires root)"
	@echo "  help      - Show this help message"
	@echo ""
	@echo "Usage examples:"
	@echo "  make                    # Build the module"
	@echo "  sudo insmod hello_kernel.ko  # Load the module"
	@echo "  dmesg | tail           # View kernel messages"
	@echo "  sudo rmmod hello_kernel      # Unload the module"

.PHONY: all modules clean install uninstall help


