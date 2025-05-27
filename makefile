CC = 1725B.cpp
CCC = "Commit-IX"
all:
	g++ $(CC)
	./a.exe
	rm ./a.exe
push:
	git add .
	git commit -m $(CCC)
	git push -u origin main
CF:
	cat template.cpp >> $(CC)