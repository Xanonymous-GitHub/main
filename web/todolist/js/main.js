$(function () {
    var add_button = document.getElementById("newsubmit");
    var inputarea = document.getElementById("newinput");
    var itemcount=1;
    add_button.addEventListener("click", function (e) {
        if(inputarea.value.trim()!=""){
            var newitem=document.createElement("p");
            newitem.className="arial";
            newitem.innerHTML=itemcount+". "+inputarea.value;
            itemcount++;
            document.getElementById("items").appendChild(newitem);
            inputarea.value="";
        }
    });
});