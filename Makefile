#           _____                    _____                    _____          
#          /\    \                  /\    \                  /\    \           
#         /::\    \                /::\____\                /::\    \        
#        /::::\    \              /::::|   |               /::::\    \       
#       /::::::\    \            /:::::|   |              /::::::\    \      
#      /:::/\:::\    \          /::::::|   |             /:::/\:::\    \     
#     /:::/  \:::\    \        /:::/|::|   |            /:::/__\:::\    \    
#    /:::/    \:::\    \      /:::/ |::|   |           /::::\   \:::\    \   
#   /:::/    / \:::\    \    /:::/  |::|   | _____    /::::::\   \:::\    \  
#  /:::/    /   \:::\ ___\  /:::/   |::|   |/\    \  /:::/\:::\   \:::\    \ 
# /:::/____/  ___\:::|    |/:: /    |::|   /::\____\/:::/  \:::\   \:::\____\
# \:::\    \ /\  /:::|____|\::/    /|::|  /:::/    /\::/    \:::\  /:::/    /
#  \:::\    /::\ \::/    /  \/____/ |::| /:::/    /  \/____/ \:::\/:::/    / 
#   \:::\   \:::\ \/____/           |::|/:::/    /            \::::::/    /  
#    \:::\   \:::\____\             |::::::/    /              \::::/    /   
#     \:::\  /:::/    /             |:::::/    /               /:::/    /    
#      \:::\/:::/    /              |::::/    /               /:::/    /     
#       \::::::/    /               /:::/    /               /:::/    /      
#        \::::/    /               /:::/    /               /:::/    /       
#         \::/____/                \::/    /                \::/    /        
#                                   \/____/                  \/____/         
#                                                                            
#           _____                    _____                                   
#          /\    \                  /\    \                                  
#         /::\____\                /::\    \                                 
#        /:::/    /               /::::\    \                                
#       /:::/   _/___            /::::::\    \                               
#      /:::/   /\    \          /:::/\:::\    \                              
#     /:::/   /::\____\        /:::/__\:::\    \                             
#    /:::/   /:::/    /       /::::\   \:::\    \                            
#   /:::/   /:::/   _/___    /::::::\   \:::\    \                           
#  /:::/___/:::/   /\    \  /:::/\:::\   \:::\    \                          
# |:::|   /:::/   /::\____\/:::/  \:::\   \:::\____\                         
# |:::|__/:::/   /:::/    /\::/    \:::\  /:::/    /                         
#  \:::\/:::/   /:::/    /  \/____/ \:::\/:::/    /                          
#   \::::::/   /:::/    /            \::::::/    /                           
#    \::::/___/:::/    /              \::::/    /                            
#     \:::\__/:::/    /               /:::/    /                             
#      \::::::::/    /               /:::/    /                              
#       \::::::/    /               /:::/    /                               
#        \::::/    /               /:::/    /                                
#         \::/____/                \::/    /                                 
#          ~~                       \/____/         

#   .--,-``-.                                                                 
#  /   /     '.    ,----..                                                    
# / ../        ;  /   /   \                                                   
# \ ``\  .`-    '|   :     :       ,---,                     .---.            
#  \___\/   \   :.   |  ;. /   ,-+-. /  |                   /. ./|            
#       \   :   |.   ; /--`   ,--.'|'   |  ,--.--.       .-'-. ' |  ,--.--.   
#       /  /   / ;   | ;  __ |   |  ,"' | /       \     /___/ \: | /       \  
#       \  \   \ |   : |.' .'|   | /  | |.--.  .-. | .-'.. '   ' ..--.  .-. | 
#   ___ /   :   |.   | '_.' :|   | |  | | \__\/: . ./___/ \:     ' \__\/: . . 
#  /   /\   /   :'   ; : \  ||   | |  |/  ," .--.; |.   \  ' .\    ," .--.; | 
# / ,,/  ',-    .'   | '/  .'|   | |--'  /  /  ,.  | \   \   ' \ |/  /  ,.  | 
# \ ''\        ; |   :    /  |   |/     ;  :   .'   \ \   \  |--";  :   .'   \
#  \   \     .'   \   \ .'   '---'      |  ,     .-./  \   \ |   |  ,     .-./
#   `--`-,,-'      `---`                 `--`---'       '---"     `--`---'    
#     ,---,                                                                   
#   .'  .' `\                                                                 
# ,---.'     \                                                                
# |   |  .`\  |                                                               
# :   : |  '  |                                                               
# |   ' '  ;  :                                                               
# '   | ;  .  |                                                               
# |   | :  |  '                                                               
# '   : | /  ;                                                                
# |   | '` ,/                                                                 
# ;   :  .'                                                                   
# |   ,.'                                                                     
# '---'                                                                       

CC = cc
SRCS =  cub3D-42/src/parse/parse_helpers.c \
        cub3D-42/src/parse/parse_helpers2.c \
        cub3D-42/src/parse/parse_helpers3.c \
		cub3D-42/src/parse/helpers.c\
        cub3D-42/src/parse/parse_map.c \
        cub3D-42/src/parse/parse_mapv2.c \
        cub3D-42/src/parse/parse_mapv3.c \
        cub3D-42/src/parse/parse.c\
        cub3D-42/src/parse/parse_outils.c\
		cub3D-42/src/parse/check_double_texture.c\
		cub3D-42/src/parse/parse_helpers4.c\
		cub3D-42/src/parse/parse_helper_3_complete.c\
		cub3D-42/src/parse/parse_helper_2_complete.c\
		cub3D-42/src/parse/parse_map_complete.c\
        cub3D-42/src_bonus/ray-casting-bonus/mini_map.c\
        cub3D-42/src_bonus/ray-casting-bonus/raycaster.c\
        cub3D-42/src_bonus/ray-casting-bonus/mlx_init.c\
        cub3D-42/src_bonus/ray-casting-bonus/utils.c\
        cub3D-42/src_bonus/ray-casting-bonus/weapon.c\
        cub3D-42/src_bonus/ray-casting-bonus/handle_frames.c\
        cub3D-42/src_bonus/ray-casting-bonus/mouse_handling.c\
        cub3D-42/src_bonus/ray-casting-bonus/handle_keypress.c\
        cub3D-42/src_bonus/ray-casting-bonus/draw.c\
        cub3D-42/src_bonus/ray-casting-bonus/raycaster_utils1.c\
        cub3D-42/src_bonus/ray-casting-bonus/draw_walls.c\
        cub3D-42/src_bonus/ray-casting-bonus/raycaster_utils.c \
		cub3D-42/src_bonus/ray-casting-bonus/draw_weapon2.c\
		cub3D-42/src_bonus/ray-casting-bonus/draw_weapon.c\
		cub3D-42/src_bonus/ray-casting-bonus/utils2.c\
		cub3D-42/src_bonus/ray-casting-bonus/raycaster_utils2.c\
		cub3D-42/src_bonus/ray-casting-bonus/mini_map_helper.c\
		main.c\
		main_cube.c\
		main_solong.c\
		So_long_42/src/moves.c So_long_42/parsing/parsing_input.c So_long_42/parsing/parsing_map.c So_long_42/src/init_data.c So_long_42/src/utils.c So_long_42/src/utils_2.c So_long_42/src/load_map.c So_long_42/src/draw_map.c\

LIB = libft/libft.a
NAME = Gnawa3D
OBJ = $(SRCS:.c=.o)

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
NC = \033[0m
BLACK = \033[0;30m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
ORANGE = \033[0;38;5;208m

all : $(NAME)

$(LIB):
	@$(MAKE) -s -C libft/
	@echo "$(GREEN)✅ Libft compiled successfully.$(NC)"

$(NAME): $(OBJ) $(LIB)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIB)
	@echo "$(GREEN)✅ $(NAME) built successfully! You can now run ./$(NAME) <map_file>.cub$(NC)"
	@echo "$(GREEN)   .--,-\`\`-.                                                                 $(NC)"
	@echo "$(GREEN)  /   /     '.    ,----..                                                    $(NC)"
	@echo "$(GREEN) / ../        ;  /   /   \                                                    $(NC)"
	@echo "$(GREEN) \ \`\`\ \  .\`-    '|   :     :       ,---,                     .---.            $(NC)"
	@echo "$(GREEN)  \___\/   \   :.   |  ;. /   ,-+-. /  |                   /. ./|            $(NC)"
	@echo "$(GREEN)       \   :   |.   ; /--\`   ,--.'|'   |  ,--.--.       .-'-. ' |  ,--.--.   $(NC)"
	@echo "$(GREEN)       /  /   / ;   | ;  __ |   |  ,\"' | /       \     /___/ \: | /       \  $(NC)"
	@echo "$(GREEN)       \  \   \ |   : |.' .'|   | /  | |.--.  .-. | .-'.. '   ' ..--.  .-. | $(NC)"
	@echo "$(GREEN)   ___ /   :   |.   | '_.' :|   | |  | | \__\/: . ./___/ \:     ' \__\/: . . $(NC)"
	@echo "$(GREEN)  /   /\   /   :'   ; : \  ||   | |  |/  ,\" .--.; |.   \  ' .\    ,\" .--.; | $(NC)"
	@echo "$(GREEN) / ,,/  ',-    .'   | '/  .'|   | |--'  /  /  ,.  | \   \   ' \ |/  /  ,.  | $(NC)"
	@echo "$(GREEN) \ ''\        ; |   :    /  |   |/     ;  :   .'   \ \   \  |--\";  :   .'   \ $(NC)"
	@echo "$(GREEN)  \   \     .'   \   \ .'   '---'      |  ,     .-./  \   \ |   |  ,     .-./$(NC)"
	@echo "$(GREEN)     ,---,                                                                   $(NC)"
	@echo "$(GREEN)   .'  .' \`\                                                                  $(NC)"
	@echo "$(GREEN) ,---.'     \                                                                 $(NC)"
	@echo "$(GREEN) |   |  .\`\  |                                                                $(NC)"
	@echo "$(GREEN) :   : |  '  |                                                                $(NC)"
	@echo "$(GREEN) |   ' '  ;  :                                                                $(NC)"
	@echo "$(GREEN) '   | ;  .  |                                                                $(NC)"
	@echo "$(GREEN) |   | :  |  '                                                                $(NC)"
	@echo "$(GREEN) '   : | /  ;                                                                 $(NC)"
	@echo "$(GREEN) |   | '\` ,/                                                                  $(NC)"
	@echo "$(GREEN) ;   :  .'                                                                    $(NC)"
	@echo "$(GREEN) |   ,.'                                                                      $(NC)"
	@echo "$(GREEN) '---'                                                                        $(NC)"
	@echo ""

	@echo "$(CYAN)--- Mandatory Controls ------|$(NC)"
	@echo "$(CYAN) W           : Move Forward  |$(NC)"
	@echo "$(CYAN) S           : Move Backward |$(NC)"
	@echo "$(CYAN) A           : Strafe Left   |$(NC)"
	@echo "$(CYAN) D           : Strafe Right  |$(NC)"
	@echo "$(CYAN) Left Arrow  : Rotate Left   |$(NC)"
	@echo "$(CYAN) Right Arrow : Rotate Right  |$(NC)"
	@echo "$(CYAN) ESC         : Exit Game     |$(NC)"
	@echo "$(CYAN)-----------------------------|$(NC)"
	@echo ""
	@echo "$(ORANGE) ____ ____ ____ ____ ____ $(NC)"
	@echo "$(ORANGE)||G |||N |||A |||W |||A ||$(NC)"
	@echo "$(ORANGE)||__|||__|||__|||__|||__||$(NC)"
	@echo "$(ORANGE)|/__\|/__\|/__\|/__\|/__\|$(NC)"
	@echo "$(YELLOW)~~~~~~ Developed by ~~~~~   $(NC)"
	@echo "$(WHITE)>> <iouhssei>$(NC)" #
	@echo "$(WHITE)   Ben Guerir, April 2025   $(NC)" #
	@echo "$(YELLOW)~~~~~~~~~~~~~~~~~~~~~~~~~$(NC)" #


%.o: %.c
	@$(CC) -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux -O3 -c $< -o $@
	@echo "$(YELLOW)Compiling: $< $(NC)" # Added echo for compilation step

clean :
	@echo "$(WHITE)✔️ --Cleaning libft objects$(NC)"
	@$(MAKE) clean -s -C libft/
	@echo "$(WHITE)✔️ --Cleaning project objects$(NC)"
	@rm -f $(OBJ)

fclean : clean
	@echo "$(WHITE)✔️ --Cleaning libft library$(NC)"
	@$(MAKE) fclean -s -C libft/
	@echo "$(WHITE)✔️ --Cleaning project executables $(NAME)"
	@rm -f $(NAME) # Remove both executables
	@echo "$(RED)✔️ --Full clean complete$(NC)"

re : fclean all

run : all
	@echo "$(GREEN)Running $(NAME)...$(NC)"
	@./$(NAME) maps/map_bonus.cub

.PHONY: all clean fclean re

.SECONDARY: $(OBJ)