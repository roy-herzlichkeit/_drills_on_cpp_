CC = 1669F.cpp
CCC = "Commit-XXX"
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