objects = lda.o file_access.o document.o 

lda : $(objects)
			g++ -o lda $(objects)

topword : topword.o

			g++ -o topword topword.o
lda.o : lda.cc lda.h file_access.h document.h
			g++ -c -o lda.o lda.cc
file_access.o : file_access.cc file_access.h
			g++ -c -o file_access.o file_access.cc
document.o : document.cc document.h
			g++ -c -o document.o document.cc

topword.o : top_word.cc
			
			g++ -c -o topword.o top_word.cc

clean : 
			rm lda $(objects)
