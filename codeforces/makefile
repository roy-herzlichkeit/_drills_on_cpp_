CC = 2161A.cpp
CCC = "Commit-LXII"
all:
	g++ -std=c++17 -O2 -Wall -Wextra $(CC)
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