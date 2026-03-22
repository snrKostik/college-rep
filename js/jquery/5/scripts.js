$("#list li").click(function() {
    // Добавляем класс кликнутому элементу, находим его соседей и удаляем класс у них
    $(this).addClass("active").siblings().removeClass("active");
});
