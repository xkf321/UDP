obj = client.o  #相当于宏定义

client:$(obj)
	gcc -ggdb3 -Wall -o  client $(obj) 

client.o:client.c 
	gcc -c $<   #-I后是需要头文件的路径

.PHONY:clean
clean:
	rm $(obj)
	
.PHONY:cleanall
cleanall:
	rm $(obj) client




