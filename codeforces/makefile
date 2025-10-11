CC = 1618C.cpp
CCC = "Commit-XXXIII"
all:
	g++ $(CC)
	./a.exe
	rm ./a.exe
commit:
	git add .
	git commit -m $(CCC)
push:
	git push -u origin main
CF:
	cat template.cpp >> $(CC)
	code $(CC)