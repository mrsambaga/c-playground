.PHONY: clean All

All:
	@echo "==========Building project:[ command-line-shell - Debug ]=========="
	@cd "command-line-shell" && "$(MAKE)" -f  "command-line-shell.mk"
clean:
	@echo "==========Cleaning project:[ command-line-shell - Debug ]----------"
	@cd "command-line-shell" && "$(MAKE)" -f  "command-line-shell.mk" clean
