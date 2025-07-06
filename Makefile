.PHONY: clean All

All:
	@echo "==========Building project:[ CTutorial - Debug ]=========="
	@cd "CTutorial" && "$(MAKE)" -f  "CTutorial.mk"
clean:
	@echo "==========Cleaning project:[ CTutorial - Debug ]----------"
	@cd "CTutorial" && "$(MAKE)" -f  "CTutorial.mk" clean
