$("#colorBtn").click(function() {
    // Генерируем случайный HEX цвет
    const randomColor = '#' + Math.floor(Math.random()*16777215).toString(16);
    $("#square").css("background-color", randomColor);
    
    // Альтернатива (чередование красного и зеленого через тернарный оператор):
    // const currentColor = $("#square").css("background-color");
    // $("#square").css("background-color", currentColor === "rgb(255, 0, 0)" ? "green" : "red");
});
