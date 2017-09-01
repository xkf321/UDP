obj = serve.o  #相当于宏定义

serve:$(obj)
	gcc -ggdb3 -Wall -o  serve $(obj) 

serve.o:serve.c 
	gcc -c $<   #-I后是需要头文件的路径

.PHONY:clean
clean:
	rm $(obj)
	
.PHONY:cleanall
cleanall:
	rm $(obj) serve




