<?php $has_sub_title = false;
if (strpos($content, '~')):
    ?>
    <?php
    $has_sub_title = true;
    $title_array = explode('~', $content);
    $main_title = $title_array[0];
    $sub_title = $title_array[1];
    ?>
    <?php endif; ?>
<div class="<?php print $class."-wrapper"; ?> title-wrapper">
<?php if ($has_sub_title): ?>
        <h3 class="<?php print $class; ?>"><?php print $main_title; ?></h3>
    <p class="block-subtitle"><?php print $sub_title; ?></p>
<?php else: ?>
        <h3 class="<?php print $class; ?>"><?php print $content; ?></h3>
<?php endif; ?>
</div> 