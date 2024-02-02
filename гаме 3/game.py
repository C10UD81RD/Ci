import numpy as np
import pygame

UNIT_SIZE = 100
ROWS = 7
COLS = 9
WINDOW_WIDTH = COLS * UNIT_SIZE
WINDOW_HEIGHT = (ROWS+1) * UNIT_SIZE


EMPTY_COLOR = (0, 0, 0)
PLAYER_COLOR = (255, 0, 0)
AI_COLOR = (0, 255, 0)
BACKGROUND_COLOR = (0, 0, 255)

FPS = 60

pygame.init()
clock = pygame.time.Clock()
window = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))

def create_board():
    return np.zeros((ROWS, COLS))

def drop_piece(board, row, col, piece):
    board[row][col] = drop_piece

def is_valid_location(board, col):
    return board[ROWS-1][col] == 0

def get_next_open_row(board, col):
    for r in range(ROWS):
        if board[r][col] == 0:
            return r

def winning_move(board, piece):
    for r in range(ROWS):
        for c in range(COLS - 3):
            if board[r][c] == piece and board[r][c+1] == piece and board[r][c+2] == piece and board[r][c+3] == piece:
                return True

    for r in range(ROWS - 3):
        for c in range(COLS):
            if board[r][c] == piece and board[r+1][c] == piece and board[r+2][c] == piece and board[r+3][c] == piece:
                return True
    
    for r in range(ROWS - 3):
        for c in range(COLS - 3):
            if board[r][c] == piece and board[r+1][c+1] == piece and board[r+2][c+2] == piece and board[r+3][c+3] == piece:
                return True
def run_game():
    running = True
    player_turn = True
    
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            elif event.type == pygame.MOUSEBUTTONDOWN and player_turn:
                x_pos, _ = event.pos
                col = x_pos // UNIT_SIZE
                
                if is_valid_location(board, col):
                    row = get_next_open_row(board, col)
                    drop_piece(board, row, col, 1)
                    if winning_move(board, 1):
                        print("Player won!")
                        running = False
                    player_turn = False
        window.fill(BACKGROUND_COLOR)
        
        for c in range(COLS):
            for r in range(ROWS):
                pygame.draw.rect(window, EMPTY_COLOR, (c * UNIT_SIZE, (r+1) * UNIT_SIZE, UNIT_SIZE, UNIT_SIZE))
                pygame.draw.circle(window, PLAYER_COLOR if board[r][c] == 1 else AI_COLOR, (c * UNIT_SIZE + UNIT_SIZE // 2, (r+1) * UNIT_SIZE + UNIT_SIZE //2), UNIT_SIZE // 2)

        pygame.display.update()
        clock.tick(FPS)
run_game()
board = create_board()
game_over = False
turn = 0
current_piece = 1

while not game_over:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            game_over = True
        if event.type == pygame.MOUSEMOTION:
            pygame. draw.rect(window, BACKGROUND_COLOR, (0, 0, WINDOW_WIDTH, UNIT_SIZE))
            pos_x = event.pos[0]
            pygame.draw.circle(window, PLAYER_COLOR, (pos_x, int(UNIT_SIZE/2)), int(UNIT_SIZE/2))
        pygame.display.update()

        if event.type == pygame.MOUSEBUTTONDOWN:
            pygame.draw.rect(window, BACKGROUND_COLOR, (0, 0, WINDOW_WIDTH, UNIT_SIZE))

            if turn % 2 == 0:
                col = int(event.pos[0] / UNIT_SIZE)
                if is_valid_location(board, col):
                    row = get_next_open_row(board, col)
                    drop_piece(board, row, col, 1)
                    if winning_move(board, 1):
                        print("You are win!")
                        game_over = True
                    turn += 1
    for c in range(COLS):
        for r in range(ROWS):
            pygame.draw.rect(window, EMPTY_COLOR, (c*UNIT_SIZE, r*UNIT_SIZE + UNIT_SIZE, UNIT_SIZE, UNIT_SIZE))
            pygame.draw.circle(window, BACKGROUND_COLOR, (c*UNIT_SIZE + int(UNIT_SIZE/2), r*UNIT_SIZE + UNIT_SIZE + int(UNIT_SIZE/2)), int(UNIT_SIZE/2))

    for c in range(COLS):
        for r in range(ROWS):
            if board[r][c] == 1:
                pygame.draw.circle(window, PLAYER_COLOR, (c*UNIT_SIZE + int(UNIT_SIZE/2), WINDOW_HEIGHT - r*UNIT_SIZE - int(UNIT_SIZE/2)),int(UNIT_SIZE/2))
            elif board[r][c] == 2:
                pygame.draw.circle(window, AI_COLOR, (c*UNIT_SIZE + int(UNIT_SIZE/2), WINDOW_HEIGHT - r*UNIT_SIZE - int(UNIT_SIZE/2)),int(UNIT_SIZE/2))
    
    pygame.display.update()
    clock.tick(FPS)

pygame.quit()
                
    
