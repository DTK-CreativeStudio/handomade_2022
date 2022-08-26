class swich{
  int x, y, color1, color2, color3,on,off;
  int val = 0;
  
  swich(int tempx,int tempy,int red,int green,int blue ,int tempon,int tempoff){
    x = tempx;
    y = tempy;
    color1 = red;
    color2 =green;
    color3 = blue;
    on = tempon;
    off = tempoff;
  }
  
void bottun(){
  resetMatrix();
  translate(x, y);
  fill(0);
  rect(-1, -1, 101, 51);

  noStroke();
  fill(color1, color2, color3);
  rect(0,0,100,50);
  stroke(0);


  strokeWeight(5);
if(mousePressed){
    if(x<=mouseX&&mouseX<=(x + 100)&&y<=mouseY&&mouseY<=(y + 50)){
        line(0, 0, 100, 0);
        line(0, 0, 0, 50);
    }

}

  line(100, 50, 0, 50);
  line(100, 50, 100, 0);

    
  }

int result(){
  if(mousePressed){
    if(x<=mouseX&&mouseX<=(x + 100)&&y<=mouseY&&mouseY<=(y + 50)){
        return on;
   }

  }
   return off;
 }

}
