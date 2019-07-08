# On FreeBSD (and systems derived from BSD) there's a dependency
# on bison(1) to be used to generate the parser.  As these
# systems have Berkeley yacc as default, there is a need to state
# this on the Makefile.  So it has been included below.  
# This way, software can be compiled in linux, Mac OS, and
# FreeBSD.

targets = zmac gendoc

toclean = $(targets)

CC=cc
CXX=c++
DEP=zmac.o mio.o doc.o zi80dis.o

# GWP - keep track of version via hand-maintained date stamp.
VERSION=\"5jan2019\"

CFLAGS+= -DVERSION="$(VERSION)"

YACC = bison -y

all: $(targets)

zmac: doc.inl $(DEP)
	$(CXX) -Wall $(CXXFLAGS) -o zmac $(DEP)

doc.inl: doc.c doc.txt
	$(CC) -Wall -DMK_DOC -o doc doc.c
	./doc >/dev/null

clean:
	rm -f zmac.c doc.inl $(DEP)
