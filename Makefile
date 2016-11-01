NAME = 42sh
LIB = srcs/libft/libft.a

#shell
SRC =  srcs/shell/main.c
SRC	+= srcs/shell/init.c
SRC	+= srcs/shell/signaux.c

#hash
SRC += srcs/hash/hash_use.c
SRC	+= srcs/hash/hash_init.c

#builtins
SRC += srcs/builtins/builtins.c
SRC += srcs/builtins/cd.c
SRC += srcs/builtins/echo.c
SRC += srcs/builtins/history.c

#env
SRC	+= srcs/env/env.c
SRC	+= srcs/env/env_lib.c
SRC	+= srcs/env/env_opt.c
SRC	+= srcs/env/set_unset.c
SRC	+= srcs/env/set_unset_tmp.c

#termcaps
SRC	+= srcs/termcaps/keyboard.c
SRC	+= srcs/termcaps/keyboard_lib.c
SRC	+= srcs/termcaps/keyboard_tools.c
SRC	+= srcs/termcaps/keyboard_tools2.c
SRC	+= srcs/termcaps/keyboard_tools3.c

#parse
SRC	+= srcs/parse/parse.c
SRC	+= srcs/parse/parse2.c
SRC	+= srcs/parse/parse3.c
SRC	+= srcs/parse/parse4.c
SRC	+= srcs/parse/parse5.c
SRC	+= srcs/parse/pre_parse.c

#history
SRC	+= srcs/history/history.c
SRC	+= srcs/history/hist_lib.c

#free
SRC	+= srcs/free_mem/free.c
SRC+= srcs/free_mem/exit.c

#debug
SRC	+= srcs/debug/debug.c

#errors
SRC	+= srcs/errors/errors.c


INC = -I srcs/libft/includes/
INC += -I srcs/shell/includes/
INC += -I srcs/hash/includes/
INC += -I srcs/parse/includes/
INC += -I srcs/termcaps/includes/
INC += -I srcs/builtins/includes/
INC += -I srcs/env/includes/
INC += -I srcs/exec/includes/
INC += -I srcs/debug/includes/
INC += -I srcs/free_mem/includes/
INC += -I srcs/history/includes/
INC += -I srcs/errors/includes/
INC += -I ./includes/

#-fsanitize=address
OBJ = $(SRC:.c=.o)
FLAG = -g -Wall -Werror -Wextra
# -fsanitize=address
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m

all: start $(NAME)

$(NAME): $(OBJ)
	@echo "\033[K$(CY)[42SH] :$(CE) $(CG)Creating Library$(CE)\033[1A";
	-@make -C srcs/libft nohd
	@echo "\033[K$(CY)[42SH] :$(CE) $(CG)Compiling 42sh ...$(CE)";
	@gcc -o $(NAME) $(FLAG) $(INC) $(SRC) -ltermcap $(LIB)

%.o: %.c
	@echo "\033[K$(CY)[42SH] :$(CE) $(CG)Compiling $<$(CE) \033[1A";
	@gcc $(FLAG) -c $< -o $@ $(INC)

start:
	@echo "\n\n"
	@echo "	$(CG)                          00000000000000000000$(CE)";
	@echo "	$(CG)                       00000000000000000000000000$(CE)";
	@echo "	$(CG)                    000000000000000000000000000000000         00   0000$(CE)";
	@echo "	$(CG)    000000        00000000000000000000000000000000000000       000000000$(CE)";
	@echo "	$(CG) 00 000000      0000000000    0000000000000    0000000000       0000000$(CE)";
	@echo "	$(CG) 000000000     0000000000      00000000000      00000000000    0000000$(CE)";
	@echo "	$(CG)   0000000    00000000000      00000000000      0000000000000000000000$(CE)";
	@echo "	$(CG)   00000000000000000000000    0000000000000    00000000000000  00000$(CE)";
	@echo "	$(CG)    000000000000000000000000000000000000000000000000000000000     000$(CE)";
	@echo "	$(CG)     000   000000000000000000000000000000000000000000000000000     0000$(CE)";
	@echo "	$(CG)    0000   000000000000000000000000000000000000000000000000000       000$(CE)";
	@echo "	$(CG)    000    0000000000000000000000000000000000000000000000 0000000000000000$(CE)";
	@echo "	$(CG)   0000000000000  0000000000000000000000000000000000000   00000000000000000$(CE)";
	@echo "	$(CG)   0000000000000   0000000000000000000000000000000000     00000000000$(CE)";
	@echo "	$(CG)  0000       0000    000000000000000000000000000000      000$(CE)";
	@echo "	$(CG)             00000     0000000000000000000000000         00$(CE)";
	@echo "	$(CG)               0000          000000000000000           000$(CE)";
	@echo "	$(CG)                00000                                0000$(CE)";
	@echo "	$(CG)                 000000      00000000000000        0000$(CE)";
	@echo "	$(CG)                   00000000     0000000000000   000000$(CE)";
	@echo "	$(CG)                      00000000000  0000000000000000$(CE)";
	@echo "	$(CG)                         000000000000000000000$(CE)";
	@echo "	$(CG)                                 00000000000000$(CE)";
	@echo "	$(CG)                                     00000000000$(CE)";
	@echo "	$(CG)                                      0000000000$(CE)";
	@echo "	$(CG)                                       0000000$(CE)";
	@echo "\n\n"
	@echo "			$(CG)        :::     ::::::::  :::::::: :::    ::: $(CE)";
	@echo "			$(CG)      :+:     :+:    :+::+:    :+::+:    :+:     $(CE)";
	@echo "			$(CG)    +:+ +:+        +:+ +:+       +:+    +:+      $(CE)";
	@echo "			$(CG)  +#+  +:+      +#+   +#++:++#+++#++:++#++       $(CE)";
	@echo "			$(CG)+#+#+#+#+#+  +#+            +#++#+    +#+        $(CE)";
	@echo "			$(CG)     #+#   #+#      #+#    #+##+#    #+#         $(CE)";
	@echo "			$(CG)    ###  ########## ######## ###    ###          $(CE)";

clean: start
	@echo "\033[K$(CY)[42SH] :$(CE) $(CG)Cleaning Library ...$(CE)\033[1A";
	-@make -C srcs/libft nohdclean
	@echo "\033[K$(CY)[42SH] :$(CE) $(CG)Cleaning 42sh objects$(CE)\033[1A";
	@/bin/rm -rf $(OBJ)

fclean: start clean
	@echo "\033[K$(CY)[42SH] :$(CE) $(CG)FCleaning Library ...$(CE)\033[1A";
	-@make -C srcs/libft nohdfclean
	@echo "\033[K$(CY)[42SH] :$(CE) $(CG)Cleaning 42sh ...$(CE)\033[1A";
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re