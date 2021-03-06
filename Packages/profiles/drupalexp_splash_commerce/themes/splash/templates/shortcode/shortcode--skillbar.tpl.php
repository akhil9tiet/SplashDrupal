<div id="<?php print $element_id; ?>" class="skill-bar" data-percent="<?php print $percent; ?>">
    <?php if ($content) : ?>
        <h6 class="upper"><?php print $content; ?></h6>
    <?php endif; ?>
    <?php if ($percent): ?>
        <div data-progress="<?php print $percent; ?>" class="progress progress-success progress-striped">
            <div class="bar"><small><?php print $percent . '%'; ?></small></div>
        </div>
    <?php endif; ?>
</div>
<script type="text/javascript">
    jQuery(document).ready(function($) {
        var $skillbar = $('#<?php print $element_id; ?>');
        var percent = $skillbar.data('percent');
        //Make sure appear plugin is loaded
        if (typeof $.fn.appear == 'function') {
            $skillbar.appear(function() {
                $skillbar.find('.bar').css({width: percent + '%'});
            });
        } else {
            $skillbar.find('.bar').css({width: percent + '%'});
        }
    });
</script>