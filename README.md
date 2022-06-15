Description
===========

	The dtchange changes  date or time the files.

Requests
========
	OS: UNIX/LINUX/WINDOWS

install
=======

	git clone https://github.com/CyberSecurityDef/dtchange.git
	cd /dtchange	
	make
	make install

Using
=====

	OPTIONS:
		-a	Date of access
		-m	Date of modificed
		-t	Time format [h:m:s] | [h-m-s] | [h.m.s]
		-d	Date format [dd:mm:yyyy] | [dd-mm-yyyy] | [dd.mm.yyyy]
		-h	Using help
	EXAMPLES:
		dtchange -a filename
		dtchange -a filename -t 13:45:50
		dtchange -m filename -d 03:05:2020
		dtchange -m filename -t 13:45:50 -d 03:05:2020


