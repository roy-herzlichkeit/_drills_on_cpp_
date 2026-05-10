CC = abc188_d.cpp
CCC = "Commit-XII"
all:
	g++ $(CC)
	./a.exe
	rm ./a.exe
push:
	git add .
	git commit -m $(CCC)
	git push -u origin main
file:
	touch $(CC)
	cat template.cpp >> $(CC)
	code $(CC)
