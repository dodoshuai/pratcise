#bin=./main
#src=$(wildcard./*.c)
#obj=$(patsubst %.c,%.o,$(src))
#.PHONY: $(bin)
#$(bin):$(obj)
#	gcc $^ -o $@
#%.o:%.c
#	gcc -c $< -o $@
#.PHONY:clean
#clean:
#	rm $(bin) $(obj)
#目标对象:依赖对象
#[tab]要执行的命令
bin=./main
#获取当前目录下以.c结尾的文件
src=$(wildcard ./*.c)
#将src的内容进行字符串替换，将.c替换成.o
obj=$(patsubst %.c, %.o, $(src))
.PHONY: $(bin)
$(bin):$(obj)
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@
.PHONY:clean
clean:
	rm $(bin) $(obj)

