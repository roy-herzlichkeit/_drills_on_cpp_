CC = 3139.cpp
CCC = "Commit-LXXIV"
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
input: 
	g++ -std=c++17 -O2 -Wall -Wextra $(CC)
	./a.exe < i.txt
	rm ./a.exe
