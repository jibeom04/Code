// alert("hello js,,,");

// let radius = 10;
// let pi = 3.1415826;
// alert(2 * radius * pi)

// fn = () => {
//   let a = 10;
//   alert('a: ' + a);
// }
// fn();

// if(273 < 52) {
//   alert('273 < 52 => treu');
// }
// alert('프로그램 종료');

// let date = new Date();
// let hours = date.getHours();
// if(hours < 12) {
//   alert("오전입니다");
// } else {
//   alert("오후입니다");
// }

// let array = [273, "문자열", true, function() { alert('1'); }, {}, [10,20]];
// alert(array[3]());

// let output = 0;
// for(let i=0; i<=100; i++) {
//   output += i;
// }
// alert(output);

// var f = () => {
//   alert("A");
// }
// function f() {
//   alert("b");
// }
// f();

let person = {
  name: " 윤인성",
  eat: function(food) {
    alert(this.name+ "이 " + food + "을/를 먹습니다.");
  }
}
person.eat("밥");