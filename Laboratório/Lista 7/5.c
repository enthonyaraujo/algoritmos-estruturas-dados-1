#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Musica {
    char titulo[100];
    char artista[100];
    int duracao;  
    struct Musica* proximo;
    struct Musica* anterior;
} Musica;

typedef struct {
    Musica* inicio;
    int tamanho;
} Playlist;

Playlist* criar_playlist() {
    Playlist* playlist = malloc(sizeof(Playlist));
    playlist->inicio = NULL;
    playlist->tamanho = 0;
    return playlist;
}

void adicionar_musica(Playlist* playlist, const char* titulo, const char* artista, int duracao) {
    Musica* nova = malloc(sizeof(Musica));
    strcpy(nova->titulo, titulo);
    strcpy(nova->artista, artista);
    nova->duracao = duracao;
    
    if (playlist->tamanho == 0) {
        nova->proximo = nova;
        nova->anterior = nova;
        playlist->inicio = nova;
    } else {
        nova->proximo = playlist->inicio;
        nova->anterior = playlist->inicio->anterior;
        playlist->inicio->anterior->proximo = nova;
        playlist->inicio->anterior = nova;
    }
    playlist->tamanho++;
}

void remover_musica(Playlist* playlist, const char* titulo) {
    if (playlist->tamanho == 0) return;
    
    Musica* atual = playlist->inicio;
    do {
        if (strcmp(atual->titulo, titulo) == 0) {
            if (playlist->tamanho == 1) {
                free(atual);
                playlist->inicio = NULL;
            } else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
                if (atual == playlist->inicio) {
                    playlist->inicio = atual->proximo;
                }
            }
            free(atual);
            playlist->tamanho--;
            return;
        }
        atual = atual->proximo;
    } while (atual != playlist->inicio);
}

void reorganizar_musica(Playlist* playlist, const char* titulo, int nova_posicao) {
    if (playlist->tamanho < 2) return;

    Musica* musica = NULL;
    Musica* atual = playlist->inicio;
    do {
        if (strcmp(atual->titulo, titulo) == 0) {
            musica = atual;
            break;
        }
        atual = atual->proximo;
    } while (atual != playlist->inicio);
    
    if (!musica) {
        printf("Música '%s' não encontrada!\n", titulo);
        return;
    }

    atual = playlist->inicio;
    for (int i = 1; i < nova_posicao && i <= playlist->tamanho; i++) {
        atual = atual->proximo;
    }

    musica->anterior->proximo = musica->proximo;
    musica->proximo->anterior = musica->anterior;
    if (musica == playlist->inicio) {
        playlist->inicio = musica->proximo;
    }

    musica->proximo = atual;
    musica->anterior = atual->anterior;
    atual->anterior->proximo = musica;
    atual->anterior = musica;
}

void exibir_playlist(Playlist* playlist) {
    if (playlist->tamanho == 0) {
        printf("Playlist vazia\n");
        return;
    }
    
    printf("\n=== PLAYLIST (%d músicas) ===\n", playlist->tamanho);
    Musica* atual = playlist->inicio;
    int pos = 1;
    int total_segundos = 0;
    
    do {
        int min = atual->duracao / 60;
        int seg = atual->duracao % 60;
        total_segundos += atual->duracao;
        printf("%2d. %s - %s (%02d:%02d)\n", pos++, atual->titulo, atual->artista, min, seg);
        atual = atual->proximo;
    } while (atual != playlist->inicio);
    
    int total_min = total_segundos / 60;
    int total_s = total_segundos % 60;
    printf("Duração total: %02d:%02d\n", total_min, total_s);
    printf("========================\n\n");
}

void proxima_musica(Playlist* playlist) {
    if (playlist->tamanho > 0) {
        printf("Próxima: %s - %s\n", playlist->inicio->titulo, playlist->inicio->artista);
    }
}

void destruir_playlist(Playlist* playlist) {
    if (playlist->tamanho == 0) {
        free(playlist);
        return;
    }
    
    Musica* atual = playlist->inicio->proximo;
    while (atual != playlist->inicio) {
        Musica* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(playlist->inicio);
    free(playlist);
}

int main() {
    Playlist* playlist = criar_playlist();
    
    adicionar_musica(playlist, "Bohemian Rhapsody", "Queen", 355);
    adicionar_musica(playlist, "Billie Jean", "Michael Jackson", 294);
    adicionar_musica(playlist, "Smells Like Teen Spirit", "Nirvana", 301);
    adicionar_musica(playlist, "Hotel California", "Eagles", 391);
    
    exibir_playlist(playlist);

    reorganizar_musica(playlist, "Smells Like Teen Spirit", 1);
    printf("Após reorganizar Nirvana para posição 1:\n");
    exibir_playlist(playlist);
    
    remover_musica(playlist, "Billie Jean");
    printf("Após remover Billie Jean:\n");
    exibir_playlist(playlist);
    
    proxima_musica(playlist);
    
    destruir_playlist(playlist);
    return 0;
}
