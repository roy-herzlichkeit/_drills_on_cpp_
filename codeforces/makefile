CC = 1846E1
CCC = "Commit-LXXXVII"
all:
	g++ -std=c++17 -O2 -Wall -Wextra $(CC).cpp
	./a.exe
	rm ./a.exe
commit:
	git add .
	git commit -m $(CCC)
push:
	git push -u origin main
code:
	cat template.cpp >> $(CC).cpp
	code $(CC).cpp