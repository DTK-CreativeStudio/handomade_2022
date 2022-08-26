class Volume{
  int haba, x, y, min, max,color1, color2, color3;
  int val = 0;


  
  Volume(int temphaba, int tempx, int tempy, int tempmin, int tempmax,int red, int green,int blue){
    haba = temphaba;
    x = tempx;
    y = tempy;
    min = tempmin;
    max = tempmax;
    color1 = red;
    color2 =green;
    color3 = blue;    
  }
  
void pre(){
   translate(x ,y);
   fill(255);
   stroke(0);
   strokeWeight(1);
   rect(0, 0, 20, 20);
   fill(255);
   rect(0, 0, haba, 20);
   fill(color1, color2, color3);
   rect(0, 0, 20, 20);
   stroke(0);
   textSize(25);
   text(0,(haba/2), 40);     
   resetMatrix();
  }



void volume(){      //mainという名前を使うとクラッシュする  
    int val = 0;
  if(mousePressed){
    //translate(x, y);      
    if(0 <= (mouseY - y)&&(mouseY - y) <= 20){
      fill(204);
      noStroke();
      fill(255);
      rect(x, y,haba+21,40);//文字を隠してる
      stroke(0);
      strokeWeight(1);
      rect(x, y, haba, 20);
      fill(255);
      if(0<=(mouseX - x)&&(mouseX - x)<=haba){
        fill(color1, color2, color3);
        rect((mouseX), y, 20, 20);
        stroke(0);
        textMode(CENTER);
        val = mouseX - x;
        val = (int)map(val, 0, haba, min, max);
        text(val,(haba/2)+x, 40+y);        
      }
      else{
        fill(color1, color2, color3);
        rect(x, y, 20, 20);
      }
    }
  }
}


int  result(){
  if(mousePressed){
   if(0 <= (mouseY - y)&&(mouseY - y) <= 20)
    if(0<=(mouseX - x)&&(mouseX - x)<=haba){
      val = mouseX - x;
      val = (int)map(val, 0, haba, min, max);
      return val;
    }
   }
  
  return val;


}
  


}
