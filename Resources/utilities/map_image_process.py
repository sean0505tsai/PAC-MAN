import cv2
maze_amount = 20

def process(mazeNo):
    img = cv2.imread('../images/png/maze/' + str(mazeNo) + '.png')
    img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    ret, output1 = cv2.threshold(img_gray, 127, 255, cv2.THRESH_BINARY_INV)     # 如果大於 127 就等於 255，反之等於 0。
    cv2.imshow('original', img)
    cv2.imshow('output', output1)
    cv2.imwrite('output/maze' + str(mazeNo) + '-white.bmp', output1)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

for i in range(1, maze_amount):
    print(i, '\n')
    process(i)