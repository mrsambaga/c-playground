.PHONY: clean All

All:
	@echo "==========Building project:[ network-programming - Debug ]=========="
	@cd "network-programming" && "$(MAKE)" -f  "network-programming.mk"
clean:
	@echo "==========Cleaning project:[ network-programming - Debug ]----------"
	@cd "network-programming" && "$(MAKE)" -f  "network-programming.mk" clean
