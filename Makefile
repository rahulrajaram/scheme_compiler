all:
	+$(MAKE) -C src

clean :
	find . -name *.o -exec rm -rf {} \; 
	find . -regex bin/* -type d -exec rm -rf {} \;
