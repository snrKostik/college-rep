$("#toggleBtn").click(function() {
    // slideToggle сам определяет, скрыт элемент или нет, и применяет slideUp или slideDown
    $("#hiddenText").slideToggle("slow");
    
    // Меняем текст кнопки в зависимости от видимости блока
    const btnText = $(this).text() === "Читать далее" ? "Скрыть" : "Читать далее";
    $(this).text(btnText);
});
