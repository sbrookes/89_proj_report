
rm -f *.bbl *.log *.aux *.out *.blg

pdflatex report.tex
bibtex report.aux
pdflatex report.tex
pdflatex report.tex

open -a Preview report.pdf