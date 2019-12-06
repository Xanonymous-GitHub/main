/*

class Message():

    def __init__(self, mix):
        self.__mix = mix
        self.__time, self.__text = self.__separate(self.__mix)

    def __separate(self, data):
        __num = list(map(str, list(range(10))))
        __i = 0
        while (data[__i] in __num):
            __i += 1
        return [self.__mix[:__i], self.__mix[__i+1:]]

    def __str__(self):
        return '%s' % self.__text

    __repr__ = __str__

    def is_read(self, time):
        return True if int(self.__time) <= time else False

*/

// class Message {
//   var __mix;
//   String __time;
//   String __text;
//   Message(String mix) {
//     this.__mix = mix;
//     [this.__time, this.__text] = this.Separate(this.__mix);
//     var response=this.Separate(this.__mix);
//     this.__time=response[0];
//   }
//   List<int> Separate(String data) {
//     List<int> num = [];
//     int c = 0;
//     for (int i = 0; i < 10; i++) {
//       num.add(i);
//     }
//     while (num.contains(data[c])) {
//       c++;
//     }
//     return [this.__mix.sublist(0, c), this.__mix.sublist(c + 1)];
//   }

//   bool Isread() {}
// }

class President{
  void Swimming(){

  }
}
class Yourbird{
  void Fly(){

  }
}

class Plane extends Yourbird{

}

class Flyfish extends Yourbird with President{
  void Fly(){

  }
}

void main() {

}