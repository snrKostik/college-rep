$("#loginForm").submit(function(e) {
    let isValid = true;

    // Сбрасываем предыдущие ошибки
    $(".error-msg").hide();

    // Проверяем каждое поле
    $(this).find("input").each(function() {
        if ($.trim($(this).val()) === "") {
            // Показываем сообщение об ошибке рядом с пустым полем
            $(this).siblings(".error-msg").show();
            isValid = false;
        }
    });

    if (!isValid) {
        // Останавливаем отправку формы, если есть ошибки
        e.preventDefault(); 
    } else {
        // Для демонстрации останавливаем реальную отправку, но выводим success
        e.preventDefault(); 
        alert("Успешно!");
        // В реальном проекте здесь бы мы убрали e.preventDefault() или отправили AJAX
    }
});
