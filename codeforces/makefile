CC = 1914D.cpp
CCC = "Commit-LXIII"
all:
	g++ $(CC)
	./a.exe
	rm ./a.exe
commit:
	git add .
	git commit -m $(CCC)
push:
	git push -u origin main
code:
	cat template.cpp >> $(CC)
	code $(CC)