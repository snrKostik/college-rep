$(".card .change-color").click(function() {
    // Поднимаемся к родителю (.card) и находим внутри него <h3>
    // Альтернатива: $(this).siblings("h3").css("color", "red");
    $(this).parent().find("h3").css("color", "red");
});
