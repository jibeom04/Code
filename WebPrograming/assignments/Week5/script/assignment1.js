let date = new Date();
let hours = date.getHours();

if(hours < 5) {
  alert("잠을 자렴....");
} else if(hours < 7) {
  alert("준비");
} else if(hours < 9) {
  alert("출근");
} else if(hours < 12) {
  alert("빈둥빈둥");
} else if(hours < 13) {
  alert("식사");
} else if(hours < 18) {
  alert("일....");
} else if(hours < 19) {
  alert("퇴근");
} else {
  alert("잘준비");
}