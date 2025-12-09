import pygame as pg
import random

#constants
RES = WIDTH, HEIGHT = 1200, 600
TILE = 30
numX = WIDTH // TILE 
numY = HEIGHT // TILE

pg.init()
screen = pg.display.set_mode(RES)
clock = pg.time.Clock()

snake = [pg.Rect(random.randint(0, numX - 1), random.randint(0, (numY - 1)), TILE, TILE)]
food = pg.Rect(random.randint(0, numX - 1), random.randint(0, numY - 1), TILE, TILE)
is_food = False
score = 0
head_dir = 0
tail_dir = 0
is_setup = True

running = True
while(running):
    screen.fill((0, 0, 0))
    for event in pg.event.get():
        if event.type==pg.QUIT:
            running = false
        if event.type == pg.KEYDOWN:
            if event.key == pg.K_ESCAPE:
                running = False
            if event.key == pg.K_UP:
                head_dir = 1
            if event.key == pg.K_RIGHT:
                head_dir = 2
            if event.key == pg.K_DOWN:
                head_dir = 3
            if event.key == pg.K_LEFT:
                head_dir = 4
            if is_setup:
                tail_dir = head_dir
                is_setup = False

    # check if there is food
    if(not is_food):
        food.x = random.randint(0, numX - 1) 
        food.y = random.randint(0, numY - 1)
        is_food = True
    #check collision of head with wall
    if(snake[0].x < 0 or snake[0].x >= numX or snake[0].y < 0 or snake[0].y >= numY):
        running = False

    #check collision of head with its body
    #if(len(snake)>1):
    #    if pg.Rect.collidelist(snake[0], snake[1:]) != -1:
    #       running = False

    #check if food is eaten
    if(pg.Rect.colliderect(snake[0], food)):
        score += 1
        is_food = False
        newBlock = pg.Rect.copy(snake[-1])
        #add new snake
        if(tail_dir == 1):
            newBlock.y += 1
        if(tail_dir == 2):
            newBlock.x -= 1
        if(tail_dir == 3):
            newBlock.y -= 1
        if(tail_dir == 4):
            newBlock.x += 1
        snake.append(newBlock)

    # move head of snake
    if(head_dir == 1):
        snake[0][1] -= 1
    if(head_dir == 2):
        snake[0][0] += 1
    if(head_dir == 3):
        snake[0][1] += 1
    if(head_dir == 4):
        snake[0][1] -= 1
    prev_x = snake[0][0]
    prev_y = snake[0][1]

    #move body of snake
    for i in range(1, len(snake)):
        temp_x, temp_y = snake[i][0], snake[i][1]
        snake[i][0] = prev_x
        snake[i][1] = prev_y
        prev_x = temp_x
        prev_y = temp_y

    # draw the snake
    for i in range(len(snake)):
        pg.draw.rect(screen, 'Green', (snake[i].x * TILE, snake[i].y * TILE, TILE, TILE))
    #draw the food
    pg.draw.rect(screen, 'Red', (food.x * TILE, food.y * TILE, TILE, TILE))
    clock.tick(60)
    pg.display.flip()
pg.quit()
