async function run(i) {
    answers = [];
    var sub_questions = $(".sub-question");
    var temp_question_ids = [];
    $.each(sub_questions, function (index, sub_question) {
        var sub_question_id = $(sub_question).attr('data-question-id');
        if ($.inArray(sub_question_id, temp_question_ids) === -1) {
            temp_question_ids.push(sub_question_id);
        }
    });
    $.each(temp_question_ids, function (index, sub_question_id) {
        var temp_score = null;
        var sub_question_essay = $(".sub-question[data-question-id='" + sub_question_id + "'][data-question-type='essay']");
        if (sub_question_essay.length) {
            temp_answer = $("textarea[data-question-id='" + sub_question_id + "']").val();
        }
        var sub_question_score = $(".sub-question[data-question-id='" + sub_question_id + "'][data-question-type='score']");
        if (sub_question_score.length) {
            temp_score = $(".range-input[data-question-id='" + sub_question_id + "']").val();
        }
        answers.push({
            id: sub_question_id,
            answer: "nice!",
            score: 87
        });

    });
    let my_data = {
        url: site_url + 'app_v2/answerEvaluation',
        type: "POST",
        data: {
            user_id: user_id,
            accessToken: accessToken,
            question_id: question_id,
            evaluation_id: i,
            answers: answers,
            device: "STUDENT_WEB"
        },
        dataType: "json"
    };
    console.log(my_data);
    $.ajax(my_data).success(function (data) {
        GAFA_answerQuestion();
        if (data.mission_event) {
            var mission_event = data.mission_event;
            $.ajax({
                url: site_url + 'student5/chicken/submitFilter',
                type: "POST",
                data: {
                    mission_event_footer: (mission_event) ? 'yes' : 'no'
                },
                dataType: "json"
            }).success(function (data) {
                getMissionEventPrize(mission_event, 'redirectBack()');
            });
        }
    });
}
(async function () {
    for (let i = 2761674;i <= 2761674; i++){
        await run(i);
    }
})()