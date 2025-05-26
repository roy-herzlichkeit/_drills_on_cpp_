CC = 2114D.cpp
CCC = "Commit-VIII"
all:
	g++ $(CC)
	./a.exe
	rm ./a.exe
push:
	git add .
	git commit -m $(CCC)
	git push -u origin main
CF:
	touch $(CC)
	cat template.cpp >> $(CC)