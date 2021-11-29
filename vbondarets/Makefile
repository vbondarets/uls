NAME	=	uls

CFLG	=	-std=c11 $(addprefix -W, all extra error pedantic) -g

SRC_DIR	= src
INC_DIR	= inc
OBJ_DIR	= obj

INC_FILES = $(wildcard $(INC_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.c=%.o)))

LMX_DIR	= libmx
LMX_A:=	$(LMX_DIR)/libmx.a
LMX_INC:= $(LMX_DIR)/inc

all: install

install: $(LMX_A) $(NAME)

$(NAME): $(OBJ_FILES)
	@clang $(CFLG) $(OBJ_FILES) -L$(LMX_DIR) -lmx -o $@
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@clang $(CFLG) -c $< -o $@ -I$(INC_DIR) -I$(LMX_INC)
	@printf "\r\33[2K$(NAME) \033[33;1mcompile \033[0m$(<:$(SRC_DIR)/%.c=%) "

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $@

$(LMX_A):
	@make -sC $(LMX_DIR)
	
clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(OBJ_DIR) in $(NAME) \033[31;1mdeleted\033[0m\n"

uninstall:
	@make -sC $(LMX_DIR) $@
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n"

reinstall: uninstall all