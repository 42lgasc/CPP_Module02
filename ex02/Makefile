# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgasc <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 18:19:19 by lgasc             #+#    #+#              #
#    Updated: 2024/10/08 19:51:56 by lgasc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Now_we_are_talking
MAIN			= main.cpp
DEFINITIONS		= METHOD_INFO=false SPECIAL_INFO=false
CLASSES			= Fixed #$(NAME)
SOURCES			= $(addsuffix .cpp, $(CLASSES)) #$(MAIN)
HEADERS			= $(addsuffix .hpp, $(CLASSES))
DEPENDENCY		= dependency.d#$(addsuffix .d, $(NAME))
DEP				= $(DEPENDENCY)
#LDLIBS			+= -lreadline
#LIBFT			= libft/libft.a
#LIB_ARCHIVES	= $(LIBFT)
#OBJECTS		= $(SOURCES:.c=.o) $(LIB_ARCHIVES)
OBJECTS			= $(SOURCES:.cpp=.o) $(LIB_ARCHIVES)

CPPFLAGS		= $(addprefix -D, $(DEFINITIONS))

# https://stackoverflow.com/a/56290397/22306298
CCFLAGS			+= -Wall -Wstrict-overflow=5 \
	-Wextra -Wmissing-format-attribute -g \
	-Wnull-dereference -Wattributes -Werror \
	-Wpedantic -Wnonnull -Wmissing-noreturn #-fPIE

GCCFLAGS		+= -Wduplicated-cond -Wattribute-alias=2 \
	-Wsuggest-attribute=malloc -Wsuggest-attribute=pure \
	-Wsuggest-attribute=const -Wsuggest-attribute=cold \
	-Wsuggest-attribute=noreturn -Wduplicated-branches \
	-Wsuggest-attribute=format -Wstringop-overflow=4

CLANGFLAGS		+= -Wproperty-attribute-mismatch

CFLAGS			+= -Wsuggest-attribute=returns_nonnull $(CCFLAGS)
ifeq ($(CC), gcc)
 CFLAGS			+= $(GCCFLAGS)
else ifeq ($(CC), clang)
 CFLAGS			+= $(CLANGFLAGS)
endif

CXXFLAGS		+= -std=c++98 $(CCFLAGS)
ifeq ($(CXX), g++)
 CXXFLAGS		+= $(GCCFLAGS)
else ifeq ($(CXX), clang++)
 CXXFLAGS		+= $(CLANGFLAGS)
endif


RESET			= \033[0m
#BOLD			= \033[1m
#FAINT			= \033[2m
#REGULAR		= \033[22m
#ITALIC			= \033[3m
#ROMAN			= \033[23m
#BLACK_FORE		= \033[30m
#OLIVE_FORE		= \033[33m
#DEFAULT_FORE	= \033[39m
#DEFAULT_BOTH	= \033[39;49m
#OLIVE_BACK		= \033[43m
#GREY_FORE		= \033[90m
#WHITE_FORE		= \033[97m
LOW_SCRIPT		= \033[22;2;23;4m
L_C				= $(LOW_SCRIPT)
# Loose inspiration from a gnu head
GNU_SCRIPT		= \033[22;1;3;24m
G_C				= $(GNU_SCRIPT)
GNU_STYLE		= \033[1;3;43;90m
G_Y				= $(GNU_STYLE)
BACKQUOTE		= `#`# Vim acts funny when a variable contains one.
REMOVING_START	= '$(G_Y)Removing $(BACKQUOTE)$(L_C)'
RM_S			= $(REMOVING_START)
REMOVING_MORE	= '$(G_C)$(BACKQUOTE), $(BACKQUOTE)$(L_C)'
RM_M			= $(REMOVING_MORE)
REMOVING_END	= '$(G_C)$(BACKQUOTE)...$(RESET)'
RM_E			= $(REMOVING_END)

DIRT			= 'TODO|FIXME|XXX|(?<!'\'')\?|\?(?!'\'')|! ?!$\
	|DEPREC\w*|[Dd]eprec\w*|(?:w?c)?log|(?<![/:])/([*/])(?! |!|\1)$\
	|(?:\t|.{4}){20}.|\b(?!$(LABEL_ALLOW))[A-Z_a-z]+:(?![":])'
LABEL_ALLOW		= By|Created|Updated|https|public|private|default|c_[a-z]+



.PHONY:	all re clean fclean

all:		$(NAME)

$(NAME):	$(MAIN) $(OBJECTS) #$(DEP) #$(MAIN) $(OBJECTS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(MAIN) $(OBJECTS) $(LDLIBS) --output $(NAME)
	-norminette
	-grep -PRn $(DIRT) --colour=auto --include='*.[cht]pp' --include='*.[ch]' \
	 --exclude='*.[cht]pp.[ch]' || echo '$(G_Y)No dirt found.$(RESET)'

clean:		
	#$(MAKE) -C $(dir $(LIBFT)) fclean
	for O in $(OBJECTS); \
	 do if [ -f $$O ]; then if [ -z $$RM ]; then echo -n $(RM_S)$$O; \
	   else echo -n $(RM_M)$$O; fi; RM=+; rm $$O; fi done; if [ -n ''$$RM ]; \
	 then echo $(RM_E); else echo '$(G_Y)No object file to remove.$(RESET)'; fi
ifeq "$(filter re, $(MAKECMDGOALS))" ""
	if [ -f $(DEP) ]; then echo $(RM_S)$(DEP)$(RM_E); rm $(DEP); \
	 else echo '$(G_Y)No dependency file to remove.$(RESET)'; fi
endif

fclean:		clean
	if [ -f $(NAME) ]; then echo $(RM_S)$(NAME)$(RM_E); rm $(NAME); \
	 else echo '$(G_Y)No executable to remove.$(RESET)'; fi

re:			fclean all

# Prevent unnecessary inclusion
# 	https://www.gnu.org/software/make/manual/make#index-MAKECMDGOALS
# 	Note how this inclusion remains a requirement of `re`.
ifeq "$(filter clean fclean, $(MAKECMDGOALS))" ""
 include $(DEP)
endif

$(DEP):		$(MAIN) $(SOURCES)
	$(CC) -MM $^ > $@
	echo -e '$(G_Y)Dependency file `$(L_C)$@$(G_C)` made.$(RESET)'
	 # This is the only place where `-e` is necessary. Why?

$(LIBFT):	
	$(MAKE) -C $(dir $@) #bonus


# Use `CC=...` or `CXX=...` instead.
#test:		$(OBJECTS)
#	- clang	$(CFLAGS) $(OBJECTS) $(LDLIBS)
#	- gcc	$(CFLAGS) $(OBJECTS) $(LDLIBS)
#	$(CC)	$(CFLAGS) $(OBJECTS) $(LDLIBS)

#$(SOURCES:.c=.o):	$@
#	echo '@$@ <$< ?$? ^$^'

# https://www.gnu.org/software/make/manual/make.html#Catalogue-of-Rules
# https://www.gnu.org/software/make/manual/make.html#Suffix-Rules
#%.o: %.cpp %.hpp
#	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) -o $@ $<
