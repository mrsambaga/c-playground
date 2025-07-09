.PHONY: clean All

All:
	@echo "==========Building project:[ c-tutorial - Debug ]=========="
	@cd "c-tutorial" && "$(MAKE)" -f  "c-tutorial.mk"
clean:
	@echo "==========Cleaning project:[ c-tutorial - Debug ]----------"
	@cd "c-tutorial" && "$(MAKE)" -f  "c-tutorial.mk" clean
