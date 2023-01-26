LATEX_FILE_NAME = file

.PHONY: build
build:
	@xelatex -shell-escape ${LATEX_FILE_NAME}.tex

.PHONY: clean
clean:
	@rm -f ${LATEX_FILE_NAME}.aux
	@rm -f ${LATEX_FILE_NAME}.fdb_latexmk
	@rm -f ${LATEX_FILE_NAME}.fls
	@rm -f ${LATEX_FILE_NAME}.log
	@rm -f ${LATEX_FILE_NAME}.out
