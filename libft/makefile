# Nom de votre bibliothèque
LIB_NAME = libft.a

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Répertoires des fichiers sources, des fichiers objets et des fichiers d'en-tête
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Utilisation de la commande shell pour récupérer tous les fichiers .c dans SRC_DIR
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)

# Génère les noms de fichiers objets à partir des fichiers source
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# La cible de la bibliothèque
$(LIB_NAME): $(OBJ_FILES)
	ar rc $@ $^
	ranlib $@

# Règle générique pour créer les fichiers objets à partir des fichiers source
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Nettoie les fichiers générés
clean:
	rm -f $(OBJ_DIR)/*.o

# Nettoie les fichiers générés et la bibliothèque
fclean: clean
	rm -f $(LIB_NAME)

# Réinstalle tout
re: fclean $(LIB_NAME)

# La cible par défaut
.PHONY: all clean fclean re
