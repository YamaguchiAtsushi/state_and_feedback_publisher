#include "state_and_feedback_publisher/state_and_feedback_publisher.hpp"

StateAndFeedbackPublisher::StateAndFeedbackPublisher() : Node("state_and_feedback_publisher"), current_state_(0)
{
    // tsukutsuku2_msgs::msg::StateAndFeedbackメッセージのパブリッシャーを作成
    publisher_ = this->create_publisher<tsukutsuku2_msgs::msg::StateAndFeedback>("/state", 10);

    // 5秒ごとにPublishStateAndFeedback関数を実行するタイマーを設定
    timer_ = this->create_wall_timer(
        std::chrono::seconds(1),
        std::bind(&StateAndFeedbackPublisher::PublishStateAndFeedback, this)
    );
}

void StateAndFeedbackPublisher::PublishStateAndFeedback()
{
    auto message = tsukutsuku2_msgs::msg::StateAndFeedback();

    message.state = 1;

    message.feed_back = 0;  // フィードバック値（例: 100）

    // メッセージをログに表示
    RCLCPP_INFO(this->get_logger(), "Publishing: State: %d, Feedback: %d", message.state, message.feed_back);

    // メッセージをパブリッシュ
    publisher_->publish(message);
}